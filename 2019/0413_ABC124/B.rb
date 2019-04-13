#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 4/13/2019, 9:01:56 PM
# Powered by Visual Studio Code
#

n = gets.to_i
h = gets.chomp.split(" ").map{|i| i.to_i}
ans = 0
for i in 0...n
  if i == 0
    ans += 1
  else
    ok = true
    for j in 0...i
      if h[j] > h[i]
        ok = false
        break
      end
    end
    if ok
      ans += 1
    end
  end
end
puts ans
