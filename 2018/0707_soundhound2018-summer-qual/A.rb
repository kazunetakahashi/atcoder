#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-7-7 21:38:18
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
if a + b == 15
  puts "+"
elsif a * b == 15
  puts "*"
else
  puts "x"
end