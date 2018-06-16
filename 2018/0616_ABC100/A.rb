#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-6-16 20:47:32
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
# s = gets.chomp

if a <= 8 && b <= 8
  puts "Yay!"
else
  puts ":("
end