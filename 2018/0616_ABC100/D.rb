#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 2018-6-16 21:07:15
# Powered by Visual Studio Code
#

n, m = gets.chomp.split(" ").map{|u| u.to_i}
x = []
y = []
z = []
n.times{
  s, q, r = gets.chomp.split(" ").map{|u| u.to_i}
  x << s
  y << q
  z << r
}

res = 0

for j in 0...2
  for k in 0...2
    for l in 0...2
      sum = []

      for i in 0...n
        t = 0
        if j == 0
          t += x[i]
        else
          t += -x[i]
        end
        if k == 0
          t += y[i]
        else
          t += -y[i]
        end
        if l == 0
          t += z[i]
        else
          t += -z[i]
        end
        sum << t
      end

      sum = sum.sort.reverse

      ans = 0

      for i in 0...m
        ans += sum[i]
      end

      res = [res, ans].max
    end
  end
end

puts res
