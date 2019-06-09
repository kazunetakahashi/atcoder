#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 6/9/2019, 8:52:56 PM
# Powered by Visual Studio Code
#

a = gets.chomp.split(" ").map{|i| i.to_i}
a.sort!
puts a[0] + a[1]
