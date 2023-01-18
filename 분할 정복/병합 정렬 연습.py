def merge_sort(messy_list: list) -> list:
	def sort(first_half: list, second_half: list) -> list:
		ret = []
		while True:
			if first_half == []:
				if second_half == []:
					return ret
				for i in second_half:
					ret.append(i)
				return ret
			if second_half == []:
				for i in first_half:
					ret.append(i)
				return ret

			if (first_half[0] <= second_half[0]):
				ret.append(first_half[0])
				del(first_half[0])
			else:
				ret.append(second_half[0])
				del(second_half[0])
	def _merge_sort(messy_list: list, list_len: int) -> list:
		if list_len <= 2:
			n = list_len // 2
			first_half, second_half = messy_list[:n], messy_list[n:]
			return sort(first_half, second_half)

		n = list_len // 2
		first_half, second_half = _merge_sort(messy_list[:n], n), _merge_sort(messy_list[n:], list_len - n)
		return sort(first_half, second_half)
		
	return _merge_sort(messy_list, len(messy_list))

#test
nums = list(map(int, input().split()))
print(merge_sort(nums))