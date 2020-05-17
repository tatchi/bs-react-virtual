// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as ReactVirtual from "react-virtual";

function App(Props) {
  var parentRef = React.useRef(null);
  var rowVirtualizer = ReactVirtual.useVirtual({
        size: 10000,
        parentRef: parentRef,
        estimateSize: React.useCallback((function (param) {
                return 35;
              }), ([])),
        scrollToFn: (function (offset, defaultScrollToFn) {
            return Curry._1(defaultScrollToFn, offset);
          })
      });
  return React.createElement("div", undefined, React.createElement("button", {
                  onClick: (function (param) {
                      return rowVirtualizer.scrollToIndex(0, {
                                  align: "auto"
                                });
                    })
                }, "ScrollToIndex"), React.createElement("button", {
                  onClick: (function (param) {
                      return rowVirtualizer.scrollToOffset(100, undefined);
                    })
                }, "ScrollToOffset"), React.createElement("div", {
                  ref: parentRef,
                  style: {
                    height: "150px",
                    overflow: "auto",
                    width: "300px"
                  }
                }, React.createElement("div", {
                      style: {
                        height: String(rowVirtualizer.totalSize) + "px",
                        position: "relative",
                        width: "100%"
                      }
                    }, Belt_Array.map(rowVirtualizer.virtualItems, (function (virtualRow) {
                            return React.createElement("div", {
                                        key: String(virtualRow.index),
                                        ref: virtualRow.measureRef,
                                        style: {
                                          height: String(virtualRow.size) + "px",
                                          left: "0px",
                                          position: "absolute",
                                          top: "0px",
                                          width: "100%",
                                          transform: "translateY(" + (String(virtualRow.start) + "px)")
                                        }
                                      }, "Row " + String(virtualRow.index));
                          })))));
}

var make = App;

export {
  make ,
  
}
/* react Not a pure module */