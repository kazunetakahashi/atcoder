#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-7-21 20:51:33
# Powered by Visual Studio Code
#

a = gets.chomp.split(" ").map{|i| i.to_i}.sort

puts (a[1] - a[0]).abs + (a[2] - a[1]).abs


