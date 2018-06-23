#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 2018-6-23 21:14:41
# Powered by Visual Studio Code
#

k = gets.to_i

a = []

for i in 0...200
  for n in 1...10
    x = n * (10 ** i) + (10 ** i) - 1
    if x > 0
      a << x
    end
    if a.size == k
      break
    end
  end
end

# for i in 0...k
#   puts a[i]
# end

def f(num)
  s = 0
  num.to_s.chars{|c|
    s += c.to_i
  }
  return num / s.to_f
end

res = 0

for i in 0...k
  if f(a[i]) >= res
    puts "f(#{a[i]}) = #{f(a[i])}"
    res = f(a[i])
  else
    puts "WA"
    puts "f(#{a[i]}) = #{f(a[i])}"
    exit
  end
end