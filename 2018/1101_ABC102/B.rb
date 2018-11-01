#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-11-1 15:53:11
# Powered by Visual Studio Code
#

n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}
puts a.max - a.min