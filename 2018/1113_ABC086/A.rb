#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 11/13/2018, 7:46:41 AM
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
if a * b % 2 == 0
  puts "Even"
else
  puts "Odd"
end