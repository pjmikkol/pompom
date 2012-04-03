#define BOOST_TEST_MODULE
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

namespace tests {

BOOST_AUTO_TEST_SUITE(testing)

BOOST_AUTO_TEST_CASE(test1) {
	BOOST_CHECK_EQUAL(1,1);
}

BOOST_AUTO_TEST_SUITE_END()

}
