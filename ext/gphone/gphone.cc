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

#ifndef GPHONE_CLASS
#define GPHONE_CLASS

namespace {
  class GPhoneException
    : public exception
  {
    PhoneNumberUtil::ErrorType errorType;
    string message;

    #define DEFAULT_MESSAGE "Not a valid phone number!";

  public:
    GPhoneException() {
      message = DEFAULT_MESSAGE;
    }

    GPhoneException(PhoneNumberUtil::ErrorType e) {
      errorType = e;

      message = DEFAULT_MESSAGE;
    }

    virtual const char* what() const throw()
    {
      return message.c_str();
    }

    virtual ~GPhoneException() throw() {

    }
  };

  class GPhone {
    string raw_number;
    string iso_country_code;
    PhoneNumber parsed_number;
    PhoneNumberUtil::PhoneNumberType type;

  public:

    GPhone(const string number, const string cc = "ZZ") {
      raw_number = number;

      PhoneNumberUtil::ErrorType er = pu().Parse(raw_number, iso_country_code, &parsed_number);

      if (er != pu().NO_PARSING_ERROR) {
        throw GPhoneException(er);
      }

      if (cc != "ZZ") {
	iso_country_code = cc;
      } else {
	pu().GetRegionCodeForNumber(parsed_number, &iso_country_code);
      }
     
      type = pu().GetNumberType(parsed_number);

    }

    string get_raw_number() { return raw_number; }
    string get_iso_country_code() { return iso_country_code; }
    uint64 get_national_number() { return parsed_number.national_number(); }
    int32 get_numeric_country_code() { return parsed_number.country_code(); }

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

    bool is_valid_for_region(const string region_code) {
      return pu().IsValidNumberForRegion(parsed_number, region_code);
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
        return "unknown";
      }
    }
  };

}
#endif
