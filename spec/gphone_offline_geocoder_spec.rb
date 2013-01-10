require File.expand_path(File.dirname(__FILE__) + '/spec_helper')

describe "GPhoneOfflineGeocoder.new()" do
  subject { GPhoneOfflineGeocoder.new() }

  it { should be }
  it { should be_an_instance_of GPhoneOfflineGeocoder }
  it "should return locations for numbers" do
    subject.get_location_for_number("12063554274").should == "Washington"
  end
end
