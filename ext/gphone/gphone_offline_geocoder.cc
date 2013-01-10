#include "rice/Class.hpp"
#include "rice/String.hpp"
#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <string>
#include <phonenumbers/phonenumberutil.h>
#include <phonenumbers/phonenumbermatcher.h>
#include <phonenumbers/geocoding/phonenumber_offline_geocoder.h>

using namespace std;
using namespace i18n::phonenumbers;
using namespace Rice;

#ifndef GPHONEOFFLINEGEOCODER_CLASS
#define GPHONEOFFLINEGEOCODER_CLASS

namespace {
  class GPhoneOfflineGeocoder {
    PhoneNumberOfflineGeocoder geocoder;

  public:
    GPhoneOfflineGeocoder() {

    }

    string get_location_for_number(string number, string locale = "en_US", string user_region = "US") {
      const PhoneNumberUtil& pu = *PhoneNumberUtil::GetInstance();

      PhoneNumber pn;
      const PhoneNumberUtil::ErrorType status = pu.Parse(number, user_region, &pn);

      assert(status == PhoneNumberUtil::NO_PARSING_ERROR);

      const string description = geocoder.GetDescriptionForNumber(pn, icu::Locale(locale.c_str()), user_region);
  
      return description;
    }
  };
}

#endif
