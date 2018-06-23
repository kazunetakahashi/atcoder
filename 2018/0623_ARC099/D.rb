#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 2018-6-23 21:14:41
# Powered by Visual Studio Code
#

k = gets.to_i

a = []

for i in 0...200
  for n in 0...10
    x = n * 10 ** i + 10 ** i - 1
    if x > 0
      a << x
    end
    if a.size == k
      break
    end
end

for i in 0...k
  puts a[i]
end

