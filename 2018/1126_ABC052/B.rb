#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 11/26/2018, 11:39:20 PM
# Powered by Visual Studio Code
#

n = gets.to_i
s = gets.chomp

x = 0
cnt = []
s.chars{|c|
  if c == 'I'
    x += 1
  elsif c == 'D'
    x -= 1
  end
  cnt << x;
}

puts cnt.max