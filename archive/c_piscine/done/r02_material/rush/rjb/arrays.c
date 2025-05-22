/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:19:37 by kzebian           #+#    #+#             */
/*   Updated: 2025/04/27 21:37:35 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_array(char **ones, char **tens, char **extra)
{
	ones[0] = "zero";
	ones[1] = "one";
	ones[2] = "two";
	ones[3] = "three";
	ones[4] = "four";
	ones[5] = "five";
	ones[6] = "six";
	ones[7] = "seven";
	ones[8] = "eight";
	ones[9] = "nine";
	ones[10] = "ten";
	ones[11] = "eleven";
	ones[12] = "twelve";
	ones[13] = "thirteen";
	ones[14] = "fourteen";
	ones[15] = "fifteen";
	ones[16] = "sixteen";
	ones[17] = "seventeen";
	ones[18] = "eighteen";
	ones[19] = "nineteen";
	tens[0] = "ten";
	tens[1] = "twenty";
	tens[2] = "thirty";
	tens[3] = "forty";
	tens[4] = "fifty";
	tens[5] = "sixty";
	tens[6] = "seventy";
	tens[7] = "eighty";
	tens[8] = "ninety";
	tens[9] = "hundred";
	extra[0] = "";
	extra[1] = "thousand";
	extra[2] = "million";
	extra[3] = "billion";
	extra[4] = "trillion";
	extra[5] = "quadrillion";
	extra[6] = "quintillion";
	extra[7] = "sextillion";
	extra[8] = "septillion";
	extra[9] = "octillion";
	extra[10] = "nonillion";
	extra[11] = "decillion";
	extra[12] = "undecillion";
}
