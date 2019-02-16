#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2/16/2019, 8:51:35 PM
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
if b % a == 0
  puts a + b
else
  puts b - a
end