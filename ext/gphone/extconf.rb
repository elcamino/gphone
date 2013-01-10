require 'mkmf-rice'

have_library('boost_thread')
have_library('phonenumber')
have_library('geocoding')
create_makefile('gphone')
