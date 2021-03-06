#include <boost/test/unit_test.hpp>

#include "libto.hpp"

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>


BOOST_AUTO_TEST_SUITE(sch_timer_test)

void echo1() {
    std::cerr << "This is the timer 5s echo ... @" << boost::this_thread::get_id() << endl;
}

void echo2() {
    std::cerr << "This is the timer 1s echo ... @" << boost::this_thread::get_id() << endl;
}

void echo3() {
    std::cerr << "This is the timer one shot echo ... @" << boost::this_thread::get_id() << endl;
}


BOOST_AUTO_TEST_CASE(test1)
{
	coroutine c1;
    c1.bind_timer(echo1, 5000, true);

    coroutine c2;
    c2.bind_timer(echo2, 1000, true);

    coroutine c3;
    c3.bind_timer(echo3, 3000, false);

    RunTask;

    return;
}

BOOST_AUTO_TEST_CASE(test2)
{
	coroutine c1;
    c1.bind_timer(echo1, 1, 5000, true);

    coroutine c2;
    c2.bind_timer(echo2, 2, 1000, true);

    coroutine c3;
    c3.bind_timer(echo3, 1, 3000, false);

    RunTask;

    return;
}


BOOST_AUTO_TEST_SUITE_END()
