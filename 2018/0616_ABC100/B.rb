#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-6-16 21:02:12
# Powered by Visual Studio Code
#

d, n = gets.chomp.split(" ").map{|i| i.to_i}

ans = 1
cnt = 0

while cnt < n
  c = 0
  t = ans
  while t % 100 == 0
    t /= 100
    c += 1
  end
  if c == d
    cnt += 1
  end
  ans += 1
end

puts ans - 1
