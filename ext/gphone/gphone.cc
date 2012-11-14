#include "rice/Class.hpp"
#include "rice/String.hpp"
#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <string>
#include <phonenumbers/phonenumberutil.h>
#include <phonenumbers/phonenumbermatcher.h>

using namespace std;
using namespace i18n::phonenumbers;
using namespace Rice;

namespace {
  class GPhoneException
    : public exception
  {
    virtual const char* what() const throw()
    {
      return "Not a valid phone number!";
    }
  };

  class GPhone {
    string raw_number;
    string country_code;
    PhoneNumber parsed_number;
    PhoneNumberUtil::PhoneNumberType type;

  public:

    GPhone(const string number, const string cc) {
      raw_number = number;
      country_code = cc;

      if (pu().Parse(raw_number, country_code, &parsed_number) != pu().NO_PARSING_ERROR) {
        throw GPhoneException();
      }

      type = pu().GetNumberType(parsed_number);

    }

    string get_raw_number() { return raw_number; }
    string get_country_code() { return country_code; }

    PhoneNumberUtil& pu() {
      return *PhoneNumberUtil::GetInstance();
    }

    const string normalize()
    {
      string formatted_number;
      pu().Format(parsed_number, PhoneNumberUtil::E164, &formatted_number);
      return formatted_number;
    }


    bool is_valid()
    {
      return pu().IsValidNumber(parsed_number);
    }

    bool is_possible()
    {
      return pu().IsPossibleNumber(parsed_number);
    }

    const string format_national()
    {
      string formatted_number;
      pu().Format(parsed_number, PhoneNumberUtil::NATIONAL, &formatted_number);
      return formatted_number;
    }

    const string get_type()
    {
      switch(type) {
      case PhoneNumberUtil::FIXED_LINE:
        return "fixed line";
      case PhoneNumberUtil::MOBILE:
        return "mobile";
      case PhoneNumberUtil::TOLL_FREE:
        return "toll free";
      case PhoneNumberUtil::PREMIUM_RATE:
        return "premium_rate";
      case PhoneNumberUtil::SHARED_COST:
        return "shared cost";
      case PhoneNumberUtil::VOIP:
        return "voip";
      case PhoneNumberUtil::PERSONAL_NUMBER:
        return "personal_number";
      case PhoneNumberUtil::PAGER:
        return "pager";
      case PhoneNumberUtil::UAN:
        return "uan";
      case PhoneNumberUtil::VOICEMAIL:
        return "voicemail";
      default:
        return NULL;
      }
    }
  };

}
extern "C"

void Init_gphone() {
  RUBY_TRY
    {
      Class rb_cGPhone = define_class<GPhone>("GPhone")
        .define_constructor(Constructor<GPhone, const string, const string>())
        .define_method("raw_number", &GPhone::get_raw_number)
        .define_method("country_code", &GPhone::get_country_code)
        .define_method("valid?", &GPhone::is_valid)
        .define_method("possible?", &GPhone::is_possible)
        .define_method("format_national", &GPhone::format_national)
        .define_method("normalize", &GPhone::normalize)
        .define_method("type", &GPhone::get_type);
    }
  RUBY_CATCH
}

