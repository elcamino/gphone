#include "rice/Class.hpp"
#include "rice/String.hpp"
#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <string>
#include <iostream>
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
      iso_country_code = cc;

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

    const string national_prefix()
    {
      string region_code;
      string national_prefix;

      pu().GetRegionCodeForCountryCode(parsed_number.country_code(), &region_code);
      pu().GetNddPrefixForRegion(region_code, true, &national_prefix);

      return national_prefix;
    }

    const string area_code()
    {
      string area_code;
      string national_significant_number;
      string region_code;

      pu().GetNationalSignificantNumber(parsed_number, &national_significant_number);
      pu().GetRegionCodeForCountryCode(parsed_number.country_code(), &region_code);


      int area_code_length = pu().GetLengthOfGeographicalAreaCode(parsed_number);

      if (area_code_length > 0) {
        area_code = national_significant_number.substr(0, area_code_length);
      } else {
        area_code = "";
      }

      return area_code;
    }

    const string subscriber_number()
    {
      string subscriber_number;
      string national_significant_number;
      pu().GetNationalSignificantNumber(parsed_number, &national_significant_number);

      int area_code_length = pu().GetLengthOfGeographicalAreaCode(parsed_number);

      if (area_code_length > 0) {
        subscriber_number = national_significant_number.substr(area_code_length, string::npos);
      } else {
        subscriber_number = national_significant_number;
      }

      return subscriber_number;
    }

    const string get_type()
    {
      switch(type) {
      case PhoneNumberUtil::FIXED_LINE:
        return "fixed line";
      case PhoneNumberUtil::MOBILE:
        return "mobile";
      case PhoneNumberUtil::FIXED_LINE_OR_MOBILE:
        return "fixed line or mobile";
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
