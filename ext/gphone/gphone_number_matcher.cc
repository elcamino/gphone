#include "rice/Class.hpp"
#include "rice/String.hpp"
#include "rice/Array.hpp"
#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <string>
#include <phonenumbers/phonenumberutil.h>
#include <phonenumbers/phonenumbermatcher.h>
#include <phonenumbers/phonenumbermatch.h>

using namespace std;
using namespace i18n::phonenumbers;
using namespace Rice;

#ifndef GPHONE_NUMBER_MATCHER_CLASS
#define GPHONE_NUMBER_MATCHER_CLASS

namespace {


  class GPhoneNumberMatcher {
    string raw_text;
    string country_code;
    Array matches;

  public:

    GPhoneNumberMatcher(const string text, const string cc) {
      PhoneNumberMatcher matcher(text, cc);
      PhoneNumberMatch m;

      while (matcher.HasNext()) {

        matcher.Next(&m);
        matches.push(String(m.raw_string()));
      }
    }

    Array numbers() {
      return matches;
    }
  };
}

#endif
