
// Copyright John Maddock 2007.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/math/policies/policy.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/test/test_exec_monitor.hpp> // for test_main
#include <iostream>

template <class P1, class P2>
bool check_same(const P1&, const P2&)
{
   if(!boost::is_same<P1, P2>::value)
   {
      std::cout << "P1 = " << typeid(P1).name() << std::endl;
      std::cout << "P2 = " << typeid(P2).name() << std::endl;
   }
   return boost::is_same<P1, P2>::value;
}


int test_main(int, char* [])
{
   using namespace boost::math::policies;
   using namespace boost;

   BOOST_CHECK(check_same(make_policy(), policy<>()));
   BOOST_CHECK(check_same(make_policy(denorm_error<ignore_error>()), normalise<policy<denorm_error<ignore_error> > >::type()));
   BOOST_CHECK(check_same(make_policy(digits2<20>()), normalise<policy<digits2<20> > >::type()));
   BOOST_CHECK(check_same(make_policy(promote_float<false>()), normalise<policy<promote_float<false> > >::type()));
   BOOST_CHECK(check_same(make_policy(domain_error<ignore_error>()), normalise<policy<domain_error<ignore_error> > >::type()));
   BOOST_CHECK(check_same(make_policy(pole_error<ignore_error>()), normalise<policy<pole_error<ignore_error> > >::type()));
   BOOST_CHECK(check_same(make_policy(indeterminate_result_error<ignore_error>()), normalise<policy<indeterminate_result_error<ignore_error> > >::type()));

   return 0;
} // int test_main(int, char* [])



