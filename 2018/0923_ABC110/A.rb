#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-9-23 20:53:43
# Powered by Visual Studio Code
#

a, b, c = gets.chomp.split(" ").map{|i| i.to_i }

puts [10 * a + b + c, a + 10 * b + c].max


