# encoding: utf-8

require 'rubygems'
require 'bundler'
begin
  Bundler.setup(:default, :development)
rescue Bundler::BundlerError => e
  $stderr.puts e.message
  $stderr.puts "Run `bundle install` to install missing gems"
  exit e.status_code
end
require 'rake'

require 'jeweler'
jeweler_tasks = Jeweler::Tasks.new do |gem|
  # gem is a Gem::Specification... see http://docs.rubygems.org/read/chapter/20 for more options
  gem.name = "gphone"
  gem.homepage = "http://github.com/elcamino/gphone"
  gem.license = "BSD"
  gem.summary = %Q{ruby bindings for Google's libphonenumber}
  gem.description = %Q{ruby bindings for Google's libphonenumber (see http://code.google.com/p/libphonenumber/)}
  gem.email = "tob@spyz.org"
  gem.authors = ["Tobias Begalke"]
  gem.files += Dir['ext/gphone/*.{cc,rb}']
  gem.require_paths = ['ext']
	gem.platform = Gem::Platform::RUBY
	gem.extensions = FileList["ext/gphone/extconf.rb"]
  # dependencies defined in Gemfile
end

$gemspec = jeweler_tasks.gemspec
$gemspec.version = jeweler_tasks.jeweler.version

Jeweler::RubygemsDotOrgTasks.new

require 'rspec/core'
require 'rspec/core/rake_task'
RSpec::Core::RakeTask.new(:spec) do |spec|
  spec.pattern = FileList['spec/**/*_spec.rb']
end

RSpec::Core::RakeTask.new(:rcov) do |spec|
  spec.pattern = 'spec/**/*_spec.rb'
  spec.rcov = true
end

task :default => :spec
task :rebuild => [:clean, :clobber, :compile, :spec]

require 'rdoc/task'
Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ""

  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "gphone #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
end

require 'rake/extensiontask'
Gem::PackageTask.new($gemspec) do |pkg|
	pkg.need_tar = false
	pkg.need_zip = false
end

Rake::ExtensionTask.new('gphone', $gemspec) do |ext|
end

CLEAN.include 'lib/**/*.so'

Rake::Task.tasks.each do |task_name|
  case task_name.to_s
    when /^native/
       task_name.prerequisites.unshift("fix_rake_compiler_gemspec_dump")
   end
end

task :fix_rake_compiler_gemspec_dump do
   %w{files extra_rdoc_files test_files}.each do |accessor|
     $gemspec.send(accessor).instance_eval { @exclude_procs = Array.new }
   end
end

