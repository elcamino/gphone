gphone
======

Ruby bindings to Google's libphonenumber. With gphone you can parse,
validate and normalize and format phone numbers and determine their
type. So far this library offers only very basic coverage of the
features the C++ library offers.

Usage
-----

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
```


Contribute
----------

Feel free to fork this repository and send me pull requests if you add
functionality.