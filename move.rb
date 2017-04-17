folder_name = "2017"

Dir.open('.').each {|dir|
  if dir[0] == '0'
    puts dir
    system("git mv #{dir}/ #{folder_name}/")
  end
}
