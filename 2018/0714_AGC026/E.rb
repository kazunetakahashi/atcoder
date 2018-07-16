#
# File    : E.rb
# Author  : Kazune Takahashi
# Created : 2018-7-16 13:05:22
# Powered by Visual Studio Code
#

n = gets.to_i
s = gets.chomp

ary = []
while !(s == "")
  a = 0
  b = 0
  for i in 0...s.size()
    if s[i] == "a"
      a += 1
    else
      b += 1
    end
    if a == b
      ary << s[0..i]
      s = s[i+1..-1]
      break
    end
  end
end

ans = []

ary.each{|str|
  num = []
  a = 0
  b = 0
  str.chars{|c|
    if c == 'a'
      num << a
      a += 1
    else
      num << b
      b += 1
    end
  }
  if str[0] == "a"
    res = ""
    _a = true
    search = nil
    for i in 0..str.size
      if _a && str[i] == 'a'
        res += str[i]
        search = num[i]
        _a = false
      else !_a && str[i] == 'b'
        if num[i] == search
          res += str[i]
          search = nil
          _a = true
        end
      end
    end
    ans << res
  else
    res = []
    for k in 0...str.size/2
      temp = ""
      for i in 0..str.size
        if num[i] >= k
          temp += str[i]
        end
      end
      res << temp
    end
    ans << res.max
  end
}

res = ""

ans.reverse.each{|str|
  if res < str + res
    res = str + res
  end
}

puts res
