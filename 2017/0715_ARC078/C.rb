n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}.sort_by{|i|
  -1 * i.abs
}
x = 0
y = 0
cx = 0
cy = 0
a.each{|i|
  if (x < y && i > 0)
    x += i
    cx += 1
  elsif (x < y && i <= 0)
    y += i
    cy += 1
  elsif (x >= y && i > 0)
    y += i
    cy += 1
  else
    x += i
    cx += 1
  end
}
if cx == 0 || cy == 0
  puts (x-y).abs + 2 * a.last.abs
else
  puts (x-y).abs
end
