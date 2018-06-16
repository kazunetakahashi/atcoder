#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-6-16 21:02:12
# Powered by Visual Studio Code
#

d, n = gets.chomp.split(" ").map{|i| i.to_i}

if n < 100
  puts (100 ** d) * n
else
  puts (100 ** d) * (n + 1)
end