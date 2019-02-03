#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2/3/2019, 8:55:05 PM
# Powered by Visual Studio Code
#

t, x = gets.chomp.split(" ").map{|i| i.to_f}
puts sprintf("%.12f", t/x)