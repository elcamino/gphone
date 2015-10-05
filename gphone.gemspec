# Generated by jeweler
# DO NOT EDIT THIS FILE DIRECTLY
# Instead, edit Jeweler::Tasks in Rakefile, and run 'rake gemspec'
# -*- encoding: utf-8 -*-
# stub: gphone 0.2.2 ruby ext
# stub: ext/gphone/extconf.rb

Gem::Specification.new do |s|
  s.name = "gphone"
  s.version = "0.2.2"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["ext"]
  s.authors = ["Tobias Begalke"]
  s.date = "2015-10-05"
  s.description = "ruby bindings for Google's libphonenumber (see http://code.google.com/p/libphonenumber/)"
  s.email = "tob@spyz.org"
  s.extensions = ["ext/gphone/extconf.rb"]
  s.extra_rdoc_files = [
    "LICENSE.txt",
    "README.md"
  ]
  s.files = [
    ".document",
    ".rspec",
    "Gemfile",
    "LICENSE.txt",
    "README.md",
    "Rakefile",
    "VERSION",
    "ext/gphone/Makefile",
    "ext/gphone/extconf.rb",
    "ext/gphone/gphone.cc",
    "ext/gphone/gphone_number_matcher.cc",
    "ext/gphone/gphone_offline_geocoder.cc",
    "ext/gphone/gphone_ruby.cc",
    "gphone.gemspec",
    "spec/gphone_number_matcher_spec.rb",
    "spec/gphone_offline_geocoder_spec.rb",
    "spec/gphone_spec.rb",
    "spec/spec_helper.rb"
  ]
  s.homepage = "http://github.com/elcamino/gphone"
  s.licenses = ["BSD"]
  s.rubygems_version = "2.4.6"
  s.summary = "ruby bindings for Google's libphonenumber"

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<rice>, [">= 0"])
      s.add_development_dependency(%q<rspec>, ["~> 2.8.0"])
      s.add_development_dependency(%q<rdoc>, ["~> 3.12"])
      s.add_development_dependency(%q<bundler>, [">= 1.0.0"])
      s.add_development_dependency(%q<jeweler>, ["~> 1.8.4"])
      s.add_development_dependency(%q<simplecov>, [">= 0"])
    else
      s.add_dependency(%q<rice>, [">= 0"])
      s.add_dependency(%q<rspec>, ["~> 2.8.0"])
      s.add_dependency(%q<rdoc>, ["~> 3.12"])
      s.add_dependency(%q<bundler>, [">= 1.0.0"])
      s.add_dependency(%q<jeweler>, ["~> 1.8.4"])
      s.add_dependency(%q<simplecov>, [">= 0"])
    end
  else
    s.add_dependency(%q<rice>, [">= 0"])
    s.add_dependency(%q<rspec>, ["~> 2.8.0"])
    s.add_dependency(%q<rdoc>, ["~> 3.12"])
    s.add_dependency(%q<bundler>, [">= 1.0.0"])
    s.add_dependency(%q<jeweler>, ["~> 1.8.4"])
    s.add_dependency(%q<simplecov>, [">= 0"])
  end
end

