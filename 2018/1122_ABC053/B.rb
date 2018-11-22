#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 11/22/2018, 7:42:02 PM
# Powered by Visual Studio Code
#

s = gets.chomp
puts s.size - s.index("A") - s.reverse.index("Z")