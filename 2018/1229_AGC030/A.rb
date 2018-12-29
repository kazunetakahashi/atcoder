#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 12/29/2018, 9:01:37 PM
# Powered by Visual Studio Code
#

a, b, c = gets.chomp.split(" ").map{|i| i.to_i}
if c >= a + b
  puts b + c
else
  puts b + (a + b)
end
