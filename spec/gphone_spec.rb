require File.expand_path(File.dirname(__FILE__) + '/spec_helper')

describe "GPhone.new('+49 09131/76352435', 'DE') (ie. with a valid number)" do
  subject { GPhone.new('+49 09131/76352435', 'DE') }

  it { should be }

  it { should be_an_instance_of GPhone }
  its(:valid?) { should be }
  its(:possible?) { should be }
  its(:raw_number) { should == '+49 09131/76352435' }
  its(:country_code) { should == 'DE' }
  its(:normalize) { should == '+49913176352435' }
  its(:format_national) { should == '09131 76352435' }
  its(:type) { should == 'fixed line' }

end


describe "GPhone.new('09543657 4567474567 4674', 'DE') (ie. with an invalid number)" do
  it { lambda { GPhone.new('09543657 4567474567 4674', 'DE') }.should raise_error }
end
