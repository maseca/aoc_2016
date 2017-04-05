function expand(s) {
	return s+'0'+s.split('').reverse().map(o=>o=='0'?'1':'0').join('');
}

function checksum(inp){
	let checksum = inp;
	let temp = "";
	len = checksum.length;

	while(len % 2 == 0){
		for(let i = 0; i < len-1; i += 2){
			if(checksum.charAt(i) == checksum.charAt(i+1))
				temp += '1';
			else
				temp += '0';
		}

		checksum = temp;
		temp = "";
		len = checksum.length;
	}

	return checksum;
}

let input = "10010000000110000";

while(input.length < 35651584){
	input = expand(input);
}

console.log(checksum(input.substring(0,35651584)));
