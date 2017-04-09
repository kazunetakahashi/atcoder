def f_or_l(str, text)
  a = str.gsub(/\?/, 'a')
  z = str.gsub(/\?/, 'z')
  if z < text
    return 2
  elsif a > text
    return 1
  else
    return 0
  end
end

n = gets.to_i
s = []
for i in 0..n
  s << gets.chomp
end
t = gets.chomp

f = 0
l = 0

s.each{|str|
  res = f_or_l(str, t)
  if res == 1
    f += 1
  elsif res == 2
    l += 1
  end
}

ans = []
for i in f..(n - l)
  ans << i
end
puts ans.join(" ")
