require File.expand_path(File.dirname(__FILE__) + '/spec_helper')

describe "GPhoneNumberMatcher" do
  subject { GPhoneNumberMatcher.new('Hier steht eine Nummer: 0211/543235-3, und hier noch eine: +1 213 542 8427.', 'DE') }

  it { should be }
  it { should be_an_instance_of GPhoneNumberMatcher }
  it "should return both numbers in the given text" do
    subject.numbers.should == ["0211/543235-3", "+1 213 542 8427"]
  end
end
