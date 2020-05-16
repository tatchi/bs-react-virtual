var Curry = require("bs-platform/lib/js/curry.js");

const tryScrollToIndex = (index, { align = 'auto', ...rest } = {}) => {
  console.log(index);
  console.log(align);
};

const scrollToIndex = (...args) => {
  tryScrollToIndex(...args);
};

// console.log(scrollToIndex.length)

Curry._2(scrollToIndex, 1, undefined)
