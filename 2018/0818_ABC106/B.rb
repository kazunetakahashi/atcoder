#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 8/18/2018, 9:02:44 PM
# Powered by Visual Studio Code
#

n = gets.to_i

ans = 0

for i in 1..n
  if i % 2 == 0
    next
  end
  cnt = 0
  for j in 1..i
    if i % j == 0
      cnt += 1
    end
  end
  if cnt == 8
    ans += 1
  end
end

puts ans