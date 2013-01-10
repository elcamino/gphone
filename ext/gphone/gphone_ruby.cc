#include "gphone.cc"
#include "gphone_offline_geocoder.cc"

extern "C"

void Init_gphone() {
  RUBY_TRY
    {
      Class rb_cGPhone = define_class<GPhone>("GPhone")
        .define_constructor(Constructor<GPhone, const string, const string>(), (Arg("number"), Arg("country_code") = (string) "ZZ"))
        .define_method("raw_number", &GPhone::get_raw_number)
        .define_method("country_code", &GPhone::get_iso_country_code)
        .define_method("numeric_country_code", &GPhone::get_numeric_country_code)
        .define_method("national_number", &GPhone::get_national_number)
        .define_method("valid?", &GPhone::is_valid)
	.define_method("valid_for_region?", &GPhone::is_valid_for_region)
        .define_method("possible?", &GPhone::is_possible)
        .define_method("format_national", &GPhone::format_national)
        .define_method("normalize", &GPhone::normalize)
        .define_method("type", &GPhone::get_type);

      Class rb_cGPhoneOfflineGeocoder = define_class<GPhoneOfflineGeocoder>("GPhoneOfflineGeocoder")
        .define_constructor(Constructor<GPhoneOfflineGeocoder>())
        .define_method("get_location_for_number", &GPhoneOfflineGeocoder::get_location_for_number, (Arg("number"), Arg("locale") = (string) "en_US", Arg("user_region") = (string) "US"));
    }
  RUBY_CATCH
}
