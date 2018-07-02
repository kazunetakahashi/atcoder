#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 2018-6-23 21:14:41
# Powered by Visual Studio Code
#

k = gets.to_i

def calc(num)
  s = 0
  num.to_s.chars{|c|
    s += c.to_i
  }
  return num / s.to_f
end

def f(num)
  ary = [[calc(num), num]]
  str = num.to_s
  for i in 0...str.size do
    c = str[i].to_i
    for j in (c + 1)..9 do
      str2 = str.dup
      str2[i] = j.to_s
      for k in (i + 1)...str.size do
        str2[k] = "9"
      end
      ary << [calc(str2.to_i), str2.to_i]
    end
  end
  return ary.min[1]
end

ans = 1
k.times{
  puts ans
  ans = f(ans + 1)
}