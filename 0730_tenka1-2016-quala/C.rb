n = gets.to_i
dic = []
n.times{
  dic << gets.chomp.split(" ")
}
$hash = {}
dic.each{|d|
  if d[0].start_with?(d[1])
    puts "-1"
    exit
  elsif d[1].start_with?(d[0])
    next
  end
  i = 0
  while d[0][i] == d[1][i]
    i += 1
  end
  if $hash[d[0][i]].nil?
    $hash[d[0][i]] = [d[1][i]]
  else
    $hash[d[0][i]] << d[1][i]
  end
}
$visited = {}
"a".upto("z"){|t|
  $visited[t] = 0
  if !$hash[t].nil?
    $hash[t].sort!.reverse!
  end
}
$ans = []

def visit(n)
  if $visited[n] == 2
    return -1
  elsif $visited[n] == 0
    $visited[n] = 2
    if !($hash[n].nil?)
      $hash[n].each{|h|
        if visit(h) == -1
          return -1
        end
      }
    end
    $visited[n] = 1
    $ans << n
    return 0
  end
end

start = []
"a".upto("z").each{|s|
  start << s
}
start.reverse!

start.each{|s|
 if $visited[s] == 0
   x = visit(s)
   if x == -1
     puts "-1"
     exit
   end
 end
}

puts $ans.reverse.join("")
