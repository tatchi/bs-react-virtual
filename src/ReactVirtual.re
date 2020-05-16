type options = {
  size: int,
  parentRef: React.ref(Js.Nullable.t(Dom.element)),
  estimateSize: int => int,
};

type virtualRow = {
  index: int,
  start: int,
  size: int,
  end_: int,
};

type returnValue = {
  virtualItems: Js.Array.t(virtualRow),
  totalSize: int,
};

[@bs.module "react-virtual"]
external useVirtual: options => returnValue = "useVirtual";