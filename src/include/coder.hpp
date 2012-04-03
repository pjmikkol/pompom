/**
 * Base for arithmetic coders.
 *
 * @author pjmikkol
 */
#include "pompom.hpp"

#include <cassert>


namespace coders {

template <typename OutStream, typename Probability, pompom::byte probabilityBits>
class Encoder {
	static_assert(sizeof(Probability)*8*2 >= probabilityBits,
								"Not enough bits in given probability-type.");

 public:
	Encoder(OutStream& out)
			: m_out(out), m_bytesWritten(0), m_left(0), m_right(s_maxProbability),
				m_delayedBits(0), m_bitsInBuffer(0), m_buffer(0) {}

	void encode(Probability left, Probability right) {
		Probability prob = m_right - m_left;
		Probability nLeft = m_left + prob*left/s_maxProbability;
		Probability nRight = m_left + prob*right/s_maxProbability;

		if (nRight < s_halfProbability) {
			output(0);
			m_left = 2*nLeft;
			m_right = 2*nRight;
			for(int i = 0; i < m_delayedBits; ++i) output(1);
			m_delayedBits = 0;
		} else if (nLeft >= s_halfProbability) {
			output(1);
			m_left = (nLeft - s_halfProbability)*2;
			m_right = (nRight - s_halfProbability)*2;
			for(int i = 0; i < m_delayedBits; ++i) output(0);
			m_delayedBits = 0;
		} else {
			while(nLeft >= s_q1Probability && nRight < s_q3Probability) {
				nLeft = (nLeft - s_q1Probability)*2;
				nRight = (nRight - s_q1Probability)*2;
				++m_delayedBits;
			}
			m_left = nLeft;
			m_right = nRight;
		}
	}

	void finish() {
		if(s_q3Probability <= m_right && m_left <= s_halfProbability) {
			output(1); output(0);
		} else {
			assert(m_left <= s_q1Probability && s_halfProbability <= m_right);
			output(0); output(1);
		}
		if(m_bitsInBuffer > 0) {
			m_out.put(m_buffer << (8 - m_bitsInBuffer));
			m_bitsInBuffer = 0;
		}
	}
	
 private:
	void output(int bit) {
		assert(m_bitsInBuffer < 8);
		++m_bitsInBuffer;
		m_buffer = (m_buffer << 1) | bit;
		if(m_bitsInBuffer == 8) {
			m_out.put(m_buffer);
			m_bitsInBuffer = 0;
		}
	}
	
	/**Stream to write. Assuming put()-function. */
	OutStream& m_out;

	pompom::uint64 m_bytesWritten;
	Probability m_left;
	Probability m_right;
	int m_delayedBits;
	pompom::byte m_bitsInBuffer;
	pompom::byte m_buffer;
	

	static const Probability s_maxProbability =
			(static_cast<Probability>(1) << probabilityBits) - 1;
	static const Probability s_halfProbability = s_maxProbability >> 1;
	static const Probability s_q1Probability = s_maxProbability >> 2;
	static const Probability s_q3Probability = 3*(s_maxProbability >> 2);
};


} //namespace coders
