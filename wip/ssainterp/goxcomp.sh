for o in darwin freebsd linux windows; 
	do for a in 386 amd64; 
		do echo "Building "$o"_"$a; GOOS=$o GOARCH=$a go build -o $o"_"$a; 
	done; 
done

