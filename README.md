gphone
======

Ruby bindings to Google's libphonenumber
(http://code.google.com/p/libphonenumber/). With gphone you can parse,
validate and normalize and format phone numbers and determine their
type. So far this library offers only very basic coverage of the
features the C++ library offers.

Usage
-----

**GPhone**

```ruby
require 'gphone'

ph = GPhone.new('+49 09131/76352435', 'DE')

ph.valid?
> true

ph.possible?
> true

ph.normalize
> "+49913176352435"

ph.format_national
> "09131 76352435"

ph.type
> "fixed line"

ph.raw_number
> "+49 09131/76352435"

ph.country_code
> 'DE'

ph.numeric_country_code
> 49

ph.national_number
> 913176352435
```

**GPhoneOfflineGeocoder**


```ruby

geocoder = GPhoneOfflineGeocoder.new()

gastgeocoder.get_location_for_number('12063554274')
> "Washington"

```

**GPhoneNumberMatcher**


```ruby

m = GPhoneNumberMatcher.new('Hier steht eine Nummer: 0211/543235-3, und hier noch eine: +1 213 542 8427.', 'DE')
m.numbers
> ["0211/543235-3", "+1 213 542 8427"]


```



Contribute
----------

Feel free to fork this repository and send me pull requests if you add
functionality.
