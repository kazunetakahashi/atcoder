#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 12/8/2018, 9:12:11 PM
# Powered by Visual Studio Code
#

n = gets.to_i
a = []
n.times{
  a << gets.to_i
}
puts a.inject(:+) - a.max/2