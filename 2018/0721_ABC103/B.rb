#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-7-21 21:16:31
# Powered by Visual Studio Code
#

s = gets.chomp
t = gets.chomp

10000.times{
  t = t[-1] + t[0..-1]
  if s == t
    puts "Yes"
    exit
  end
}

puts "No"
