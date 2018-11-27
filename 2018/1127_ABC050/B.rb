#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 11/27/2018, 8:28:59 PM
# Powered by Visual Studio Code
#

n = gets.to_i
t = gets.chomp.split(" ").map{|i| i.to_i}
m = gets.to_i
problems = []
m.times{
  problems << gets.chomp.split(" ").map{|i| i.to_i}
}
sum = t.inject(:+)
problems.each{|prob|
  puts sum - t[prob[0] - 1] + prob[1]
}