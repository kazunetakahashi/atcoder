#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 8/18/2018, 9:05:13 PM
# Powered by Visual Studio Code
#

s = gets.chomp
k = gets.to_i

if s[0] != "1"
  puts s[0]
else
  for i in 0...([k, s.size()].min)
    if s[i] != "1"
      puts s[i]
      exit
    end
  end
  puts "1"
end


