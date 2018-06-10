#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-6-10 21:02:48
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}

x = b - a

puts x * (x + 1) / 2 - b