#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-6-3 21:00:30
# Powered by Visual Studio Code
#

n = gets.to_i
ans = 0

for a in 1...n
  b = n - a
  sum = 0
  a.to_s.chars{|c|
    sum += c.to_i
  }
  b.to_s.chars{|c|
    sum += c.to_i
  }
  ans = [ans, sum].max
end

puts ans