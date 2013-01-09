require File.expand_path(File.dirname(__FILE__) + '/spec_helper')

describe "GPhone.new('+49 09131/76352435', 'DE') (ie. with a valid number)" do
  subject { GPhone.new('+49 09131/76352435', 'DE') }

  it { should be }

  it { should be_an_instance_of GPhone }
  its(:valid?) { should be }
  it "should be valid for region 'DE'" do
    subject.valid_for_region?('DE').should be
  end

  it "should not be valid for region 'US'" do
    subject.valid_for_region?('US').should_not be
  end
  its(:possible?) { should be }
  its(:raw_number) { should == '+49 09131/76352435' }
  its(:country_code) { should == 'DE' }
  its(:numeric_country_code) { should == 49 }
  its(:national_number) { should == 913176352435 }
  its(:normalize) { should == '+49913176352435' }
  its(:format_national) { should == '09131 76352435' }
  its(:type) { should == 'fixed line' }

end


describe "GPhone.new('09543657 4567474567 4674', 'DE') (ie. with an invalid number)" do
  it { lambda { GPhone.new('09543657 4567474567 4674', 'DE') }.should raise_error }
end

describe "GPhone.new('+12069735100') (i.e. a fully qualified number)" do
  subject { GPhone.new('+12069735100') }

  it { should be }

  it { should be_an_instance_of GPhone }
  its(:valid?) { should be }
  it "should not be valid for region 'DE'" do
    subject.valid_for_region?('DE').should_not be
  end

  it "should be valid for region 'US'" do
    subject.valid_for_region?('US').should be
  end
  its(:possible?) { should be }
  its(:country_code) { should == 'US' }
  its(:numeric_country_code) { should == 1 }
  its(:national_number) { should == 2069735100 }
  its(:normalize) { should == '+12069735100' }
  its(:format_national) { should == '(206) 973-5100' }
  its(:type) { should == "unknown" }
end

describe "GPhone.new('12345234') (ie. with an invalid number)" do
  it { lambda { GPhone.new('12345234') }.should raise_error }
end
